$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = '/home/controls/support/seq-2.2.3';
$ENV{PATH} = '/home/controls/support/seq-2.2.3/bin/linux-x86_64:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:/home/epics/.local/bin:/home/epics/bin:/home/epics/base/bin/linux-x86_64:/home/epics/base/../extensions/bin/linux-x86_64:/home/epics/base/bin/linux-x86_64:/home/epics/base/../extensions/bin/linux-x86_64:/home/epics/base/bin/linux-x86_64:/home/epics/base/../extensions/bin/linux-x86_64';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
my $pid = fork();
die "fork failed: $!" unless defined($pid);
if (!$pid) {
  exec("./norace -S -d ../norace.db");
  die "exec failed: $!";
}
system("./norace -S -t");
kill 9, $pid or die "kill failed: $!";
