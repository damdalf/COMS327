WINDOW *wbody, *inner;
FIELD **field;
FORM *form;
int nb_field; // how many fields you want
int cur_y = 1, cur_x = 1; // current y and x for the inner window
int label_size, field_size;
char str_label[14], str_field[39];
int ch;
int cur_page = 0;
int lines;

lines = num_trainers;

/*
 * This is a simple example of "scrolling" form with ncurses.
 * It use "page" to allow forms with more fields than your window can print.
 *
 * It prints a "label" (inactive field) and a regular field and let you
 * "scroll" pages of the form.
 *
 * How to compile:
 *	gcc -o test scrolling_form.c -lform -lncurses
 */

/*

+----------------------------------+ <-- wbody
|+--------------------------------+ <-- inner
||  ^                             ||
||  |                             ||
||  |                             ||
||  |                             ||
||  | lines                       ||
||  |                             ||
||  |                             ||
||  |                             ||
||  v                             ||
|+--------------------------------+|
+----------------------------------+

 */

void quit_scroll_window()
{
    int i;

    unpost_form(form);

    for (i = 0; i < nb_field; i++) {
        free(field_buffer(field[i], 0));
        free_field(field[i]);
    }

    free_form(form);
    delwin(wbody);
    delwin(inner);
}

const char* get_next_str_field()
{
    int y;
    int x;
    int ew_difference;
    int sn_difference;

    // Increment through the cmap and check if an entry is not NULL or not the PC.
    for (y = 0; y < MAP_Y; y++)
    {
        for (x = 0; x < MAP_X; x++)
        {
            if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] != char_pc)
            {
                // Calculate W or E distance:
                ew_difference = world.pc.pos[dim_x] - x;
                // Calculate S or N distance:
                sn_difference = world.pc.pos[dim_y] - y;

                // East.
                if (ew_difference < 0 && sn_difference < 0)
                {
                    field_size = 38;
                    char *temp = malloc(39);
                    sprintf(temp, "%d move(s) East, %d move(s) South.", (abs(ew_difference)), abs(sn_difference));
                    return temp;
                }
                else if (ew_difference < 0 && sn_difference > 0)
                {
                    field_size = 38;
                    char *temp = malloc(39);
                    sprintf(temp, "%d move(s) East, %d move(s) North.", abs(ew_difference), abs(sn_difference));
                    return temp;
                }
                else if (ew_difference < 0)
                {
                    field_size = 18;
                    char *temp = malloc(19);
                    sprintf(temp, "%d move(s) East.", abs(ew_difference));
                    return temp;
                }
                    // West.
                else if (ew_difference > 0 && sn_difference < 0)
                {
                    field_size = 38;
                    char *temp = malloc(39);
                    sprintf(temp, "%d move(s) West, %d move(s) South.", abs(ew_difference), abs(sn_difference));
                    return temp;
                }
                else if (ew_difference > 0 && sn_difference > 0)
                {
                    field_size = 38;
                    char *temp = malloc(39);
                    sprintf(temp, "%d move(s) West, %d move(s) North.", abs(ew_difference), abs(sn_difference));
                    return temp;
                }
                else if (ew_difference > 0)
                {
                    field_size = 18;
                    char *temp = malloc(19);
                    sprintf(temp, "%d move(s) West.", abs(ew_difference));
                    return temp;
                }
                    // Only South.
                else if (ew_difference == 0 && sn_difference < 0)
                {
                    field_size = 19;
                    char *temp = malloc(20);
                    sprintf(temp, "%d move(s) South.", abs(sn_difference));
                    return temp;
                }
                    // Only North.
                else if (ew_difference == 0 && sn_difference > 0)
                {
                    field_size = 19;
                    char *temp = malloc(20);
                    sprintf(temp, "%d move(s) North.", abs(sn_difference));
                    return temp;
                }
                // On the PC.
                else return "TRAINER IS CURRENTLY ON THE PC.";
                // Increment the position of the cursor in the menu.
            }
        }
    }
    return "ERROR";
}

const char* get_next_str_label()
{
    int x, y;
    char* temp;

    // Increment through the cmap and check if an entry is not NULL or not the PC.
    for (y = 0; y < MAP_Y; y++)
    {
        for (x = 0; x < MAP_X; x++)
        {
            if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x]->symbol != PC)
            {
                switch (world.cur_map->cmap[y][x]->symbol)
                {
                    case HIKER:
                        label_size = 5;
                        temp = malloc(6);
                        sprintf(temp, "HIKER:");
                        return temp;
                    case RIVAL:
                        label_size = 5;
                        temp = malloc(6);
                        sprintf(temp, "RIVAL:");
                        return temp;
                    case PACER:
                        label_size = 5;
                        temp = malloc(6);
                        sprintf(temp, "PACER:");
                        return temp;
                    case WANDERER:
                        label_size = 8;
                        temp = malloc(9);
                        sprintf(temp, "WANDERER:");
                        return temp;
                    case RANDOM_WALKER:
                        label_size = 13;
                        temp = malloc(14);
                        sprintf(temp, "RANDOM WALKER:");
                        return temp;
                    case STATIONARY:
                        label_size = 10;
                        temp = malloc(11);
                        sprintf(temp, "STATIONARY:");
                        mvprintw(temp, 1, 1);
                }
            }
        }
    }
    return "ERROR";
}

/*
 * Create nb_field fields, one as a label, one as an active field e.g.:
 *	[label]:	[field]
 */
void create_nb_fields() {
    int i;

    field = calloc(nb_field, sizeof(FIELD *));

    if (!field) // No memory for you !
        assert(1);

    for (i = 0; i < nb_field-1; i++, cur_y += 2) {
        // label
        field[i] = new_field(1, lines - 1, cur_y, cur_x, 0, 0);
        field_opts_on(field[i], O_VISIBLE);
        field_opts_off(field[i], O_EDIT);
        field_opts_off(field[i], O_ACTIVE);
        set_field_buffer(field[i], 0, get_next_str_label());

        i++;

        /*
         * This is a nasty tric:
         * I check if we wrote at the tail of the inner window,
         * if so, I move the field where it belongs (head of
         * the inner window).
         */
        if (cur_y % lines == 0) {
            cur_y = 1;
            set_new_page(field[i-1], TRUE);
            move_field(field[i-1], cur_y, cur_x);
        }

        // field
        field[i] = new_field(1, lines - 1, cur_y, cur_x + 10, 0, 0);
        set_field_back(field[i], A_UNDERLINE);
        field_opts_on(field[i], O_VISIBLE);
        field_opts_on(field[i], O_ACTIVE);
        field_opts_off(field[i], O_EDIT);
        set_field_buffer(field[i], 0, get_next_str_field());
    }

    field[nb_field-1] = NULL;
}

void scroll_window()
{
    initscr();
    stdscr = newwin(24, 80, 0, 0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // This is required to init get_next_str_XXXX
//    str_label[0] = '\0';
//    str_field[0] = '\0';

    wbody = newwin(lines + 2, 80, 0, 0);
    box(wbody, 0, 0);
    keypad(wbody, TRUE);

    nb_field = 74; // this is too much fields for the window
    create_nb_fields();
    form = new_form(field);

    // Check the doc here:
    // http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/forms.html#FORMWINDOWS
    set_form_win(form, wbody);
    inner = derwin(wbody, lines, 78, 1 ,1);
    set_form_sub(form, inner);

    post_form(form);

    refresh();

    while ((ch = wgetch(wbody)) != 27) {
        switch (ch) {
            case KEY_RIGHT:
                form_driver(form, REQ_NEXT_FIELD);
                form_driver(form, REQ_END_LINE);
                break;

            case KEY_LEFT:
                form_driver(form, REQ_PREV_FIELD);
                form_driver(form, REQ_END_LINE);
                break;

                /*
                 * This is where you want to look to see how
                 * to "scroll" to the next/previous page.
                 */
            case KEY_DOWN:
                form_driver(form, REQ_NEXT_PAGE);
                set_form_page(form, ++cur_page);
                break;

            case KEY_UP:
                form_driver(form, REQ_PREV_PAGE);
                set_form_page(form, --cur_page);
                break;
        }
    }

    quit_scroll_window();
    endwin();
}

scroll_window();
