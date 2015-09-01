-module('systemcmd').
-on_load(init/0).
-export([cmd/1]).

-define(APPNAME, systemcmd).
-define(LIBNAME, systemcmd).

init() ->
    SoName = case code:priv_dir(?APPNAME) of
        {error, bad_name} ->
            case filelib:is_dir(filename:join(["..", priv])) of
                true ->
                    filename:join(["..", priv, ?LIBNAME]);
                _ ->
                    filename:join([priv, ?LIBNAME])
            end;
        Dir ->
            filename:join(Dir, ?LIBNAME)
    end,
    erlang:load_nif(SoName, 0).

cmd(_) ->
    exit(nif_library_not_loaded).
