systemcmd
=====

Erlang NIF for the C `system` function. Erlang has a `os:cmd` function but
it doesn't return the exit status of a command, instead it returns it's
standard output. I really needed this for a project and thought it would be
a fun exercise in binding C and Erlang code.

We only expose a single function:

```erlang
Eshell V6.4  (abort with ^G)
1> Status = systemcmd:cmd("ls").
LICENSE      README.md    _build       c_src        priv         rebar.config rebar.lock   src
                                                                                              0
2> Status = 0.
0
3>
```

This is too simple to work with all cases, if you ever use this and run into
and issue let me know. I'll try my best to get it fixed.

Build
-----

    $ rebar3 compile
