# **COM S 327: Day Three - Make Files | 1/25/22 |**

## **Submissions**:
* README
    * About 150 words or less, briefly describe (short paragraph) what the program does.
    * Information regarding known bugs, especially those that impair functionality-testing. 
        * You won't get a horrible score for being unable to fix a bug, but just inform the TA about the bug and how to avoid it - more likely for them to be lenient.
    * Information regarding any interesting ways you went about solving the problem - if you did something cool, talk about it!
* CHANGELOG
    * Should be a timestamp of the things that you've changed over the course of development.
```
Jan 19: Started writing Knight's Tour.
Jan 21: Added recursive backtracking algorithm; still debugging.
Jan 25: Removed infinite recursion, project is completed.
```
* PRIOR TO THE SUBMISSION - MAKING TARBALLS:
```
# run 'make clean' to remove the binaries
---
make clean

# move into the parent directory to be able to make a tarball of the current directory
---
cd ..

# make a copy of the directory to ensure the name will meet submission criteria
---
cp -R originalDirectory assignment_username

# now, it's time to create the tarball. there are four switches to tar: 'c' means create, 'v' means verbose, 'f' means force, and 'z' means compress with gzip.
---
tar cvfz assignment_username.tar.gz assignment_username

# while you could be done here, you do want to risk receiving a penalty on your grade for doing it incorrectly. thus, let's test it out. however, you cannot expand the tar here since the target directory already exists. so, let's make a temporary directory to expand the tar in.
---
mkdir test

# now, lets move into it.
---
cd test

# now, let's open up the archive to make sure everything went smoothly. gzip decompresses and compresses: the 'd' switch tells gzip to decompress the tar. the 'c' switch tells gzip to concatenate the output to the standard out, then we pipe '|' that to tar, where the 'x' switch means to expand, the 'v' switch means verbose, the 'f' switch means to force, and a file name of '-' means to read the file from the standard input. this should display all of the files that are stored in the tar. if nothing is missing, then good! to be extra sure, you can move into the directory, do a build, some testing, etc. 
---
gzip -dc ../assignment_username.tar.gz | tar xvf -

# if everything looks good, then awesome! since you don't need the temporary directory or the renamed directory, you can remove them.
---
rm -rf test assignment_username
```

## **Make files:**
* ```Makefile```
    * Simply a .txt file, but do not create the file with a file extension.
```txt
target: dependency list
    command(s) to build target from dependencies
```
* Once the Makefile has been made, simply run ```make``` within the directory in which both the target and Makefil exist.
* If there are multiple ```Makefiles``` in the directory, make you sure provide the name of the target you're wanting to compile. 
    * ```make target```
* Ex) ```hello.c```
```txt
hello: hello.c
    gcc hello.c -o -Wall -Werror hello
clean:
    rm -f *~ hello core
```
* To compile: ```make hello```
* Ex) ```hello.java```
```txt
hello.class: hello.java
    javac hello.java
clean: rm -f *~ hello.class core
```
* To compile: ```make hello.class```

* Ex) multiple files
```txt
all: hello times_table hello.class

hello: hello.c
    gcc hello.c -o -Wall -Werror hello
times_table: times_table.c
    gcc times_table.c -o -Wall -Werror times_table
hello.class: hello.java
    javac hello.java
clean:
    rm -f *~ hello times_table hello.class core
```
* Ex) multiple files and optimizing build time (building files in multiple steps)
```txt
all: hello times_table hello.class

hello: hello.o
    gcc hello.o -o hello
hello.o: hello.c
    gcc -c hello.c -Wall -Werror 
times_table: times_table.o
    gcc times_table.o -o times_table
times_table.o: times_table.c
    gcc -c times_table.c -Wall -Werror
clean:
    rm -f *~ hello.o hello times_table hello.class core
```

