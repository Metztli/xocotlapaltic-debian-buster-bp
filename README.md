Xocotlapaltic means 'Strawberry' in Nahuatl, *real* Mexico's language par excellence.

This hack is based on Strawberry https://github.com/jonaski/strawberry by Jonas Kvinge <jonas@jkvinge.net>

My couple of years old Strawberry build on Metztli Reiser4
 ( https://sourceforge.net/projects/metztli-reiser4/ ) which originally was based on Debian 9 Stretch,
reached end of life (EOL) as Metzlti Reiser4 was upgraded to use Debian Buster for AMD64.

And just like two years ago, I had an extra hard time building Strawberry for Debian Buster AMD64.
Used to follow roughly the 'Debian way' of building software, I ripped Debian Packaging for Clementine,
to be used for building Strawberry. I only left the copyright related files.

In particular, this line was removed:

configure_file(${CMAKE_SOURCE_DIR}/debian/changelog.in ${CMAKE_SOURCE_DIR}/debian/changelog)

(found in dist/CMakeLists.txt) as it wreaks havoc when using dch to annotate debian/changelog
 *and* if the original debian/changelog.in is not found, the build stops with a nasty and
 confusing message:

/usr/bin/ld: cannot find -lpthreads
collect2: error: ld returned 1 exit status

leading the software builder, i.e., myself, to scan the Web for erroneous solutions.


Notwithstanding, I managed to build Strawberry Music Player in my reiser4 environment after all.

After fulfilling dependencies (found in debian/control file) the software builder merely has to 
execute:

dpkg-buildpackage [-d] -F -us -uc -jX -T binary-arch,binary-indep

where [-d] is optional (please read man dpkg-buildpackage),

and X is the number of cores to be assigned to the Strawberry build task.

Oh, and the builder is free to use dch to modify the debian/changelog file ;-)


Huelmati (Enjoy)!
