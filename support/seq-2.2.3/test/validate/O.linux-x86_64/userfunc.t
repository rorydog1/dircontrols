$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = '/home/controls/support/seq-2.2.3';
$ENV{PATH} = '/home/controls/support/seq-2.2.3/bin/linux-x86_64:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:/home/epics/.local/bin:/home/epics/bin:/home/epics/base/bin/linux-x86_64:/home/epics/base/../extensions/bin/linux-x86_64:/home/epics/base/bin/linux-x86_64:/home/epics/base/../extensions/bin/linux-x86_64:/home/epics/base/bin/linux-x86_64:/home/epics/base/../extensions/bin/linux-x86_64';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
system "./userfunc -S -t -d ../userfunc.db";
