# 1 "../sync_not_monitored.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../sync_not_monitored.st"






program p

int x;
assign x;
evflag f;
sync x to f;

# 1 "../simple.st" 1






ss simple {
    state simple {
        when () {} exit
    }
}
# 14 "../sync_not_monitored.st" 2
