// Copyright 2019-2022 Lawrence Livermore National Security, LLC and other
// Variorum Project Developers. See the top-level LICENSE file for details.
//
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <variorum_config.h>
#include <getopt.h>
#include <variorum.h>

int main(int argc, char **argv)
{
    const char *usage = "Usage: %s [-h] \n";
    int opt;
    while ((opt = getopt(argc, argv, "hv")) != -1)
    {
        switch (opt)
        {
            case 'v':
                printf(QuoteMacro(VARIORUM_VERSION)"\n");
                return 0;
                break;
            case 'h':
                printf(usage, argv[0]);
                return 0;
                break;
            default:
                fprintf(stderr, usage, argv[0]);
                return -1;
        }
    }
    int ret;

    ret = variorum_print_energy();
    if (ret != 0)
    {
        printf("Print core and Socket energy failed!\n");
    }
    return ret;
}
