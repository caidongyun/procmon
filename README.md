procmon
=======

Process monitoring and alert system on Linux

Registration
============
Registration will be automatic with the client application using TCP SIN style approach. The client will connect on Unix socket.
Procmon will send a random number and client should reply with N+1. This will complete the registration process.


Each process need to be registered with procmon. By default it will wait for 2+2 seconds before shooting the process.
Process could be local or remote. For remote process, remote system should have procmon installed. One procmon can manage
multiple distributed procmons.
