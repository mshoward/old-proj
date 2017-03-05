###Implentation of socket.h

---

Implements socket.h to accept a single connection.

Ideal use is:

- init()
- start()
- acceptConnection()
- startAndDetatchReadThread()
- read from the output queue object until time to quit
- then call stopReadThread() - stopReadThread blocks until the reading thread has stopped.
