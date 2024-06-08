set ns [new Simulator]

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# Creating duplex links with specified bandwidth and delay
$ns duplex-link $n0 $n2 2Mbps 10ms DropTail
$ns duplex-link $n1 $n2 2Mbps 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mbps 20ms DropTail

# Setting queue size for each node
$n0 queue-limit 10
$n1 queue-limit 10
$n2 queue-limit 10
$n3 queue-limit 10

# Creating agents and attach them to nodes
set tcpAgent [$ns create-agent "tcp" TCP]
set sinkAgent [$ns create-agent "tcp" TCP]
set udpAgent [$ns create-agent "udp" UDP]
set nullAgent [$ns create-agent "null" Null]

$ns attach-agent $n1 $tcpAgent
$ns attach-agent $n3 $sinkAgent
$ns attach-agent $n0 $udpAgent
$ns attach-agent $n3 $nullAgent

# Creating traffic generators and attach them to agents
set ftp [$ns create-ftp "ftp" $tcpAgent 0.5 4.0]
set cbr [$ns create-cbr "cbr" $udpAgent 100Kb 0.1 4.5]

$ns color $tcpAgent "blue"
$ns color $udpAgent "red"

# Scheduling events for start and stop of traffic generators
$ns at 0.1 "$cbr start"
$ns at 4.5 "$cbr stop"
$ns at 0.5 "$ftp start"
$ns at 4.0 "$ftp stop"

$ns trace-all $ns

$ns run