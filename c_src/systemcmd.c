#include <stdlib.h>
#include "erl_nif.h"

#define SYSTEMCMD_MAX_COMMAND_LEN 255

extern int cmd(const char *x);

static ERL_NIF_TERM cmd_nif(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    int ret;
    char command[SYSTEMCMD_MAX_COMMAND_LEN];

    if (!enif_get_string(
            env, argv[0], command, SYSTEMCMD_MAX_COMMAND_LEN, ERL_NIF_LATIN1
        ))
    {
        return enif_make_badarg(env);
    }

    ret = system(command);

    return enif_make_int(env, ret);
}

static ErlNifFunc nif_funcs[] = {
    {"cmd", 1, cmd_nif}
};

ERL_NIF_INIT(systemcmd, nif_funcs, NULL, NULL, NULL, NULL);
