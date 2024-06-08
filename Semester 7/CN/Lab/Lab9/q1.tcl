puts "Enter a number greater than 4: "
flush stdout
set number [gets stdin]

if {![string is integer $number] || $number <= 4} {
    puts "Invalid input. Please enter a number greater than 4."
} else {
    set number [expr {$number + 0}]

    if {$number % 2 == 0} {
        for {set i 4} {$i <= $number} {incr i 2} {
            puts $i
        }
    } else {
        for {set i 3} {$i <= $number} {incr i 2} {
            puts $i
        }
    }
}
