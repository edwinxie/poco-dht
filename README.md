About
=====

Simple distributed hash table library project, using poco libraries.


Current state
=============

Not usable yet.


Todo
====

* protocol versionning

* packet structure

* simple configuration-file settings

* node identifier class (including random-based generation for first run, ...)

* distance computation between two given keys

* routing table lookups

* basic protocol messages

* incoming request processing

* outgoing request sender

* simple http-based management interface (including templating engine, ...) ?

* proper platform checks using CMake :)

* ... many more things


History
=======

* December 15th 2011: added build support for cygwin, using poco libraries v1.4.2p1

* September 6th 2011: initial set of simple classes, progressively modeling our basic entities.

* September 5th 2011: splitted our simple node project in two parts ; simple shared library and sample node application.

* August 14th 2011: initial listening socket using the poco library ( http://poco.sourceforge.net/ ).


