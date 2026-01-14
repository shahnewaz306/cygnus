# Output image
set terminal png size 800,600
set output "error_plot.png"

# Log-log scale
set logscale xy

# Axis labels and title
set xlabel "Step size h"
set ylabel "Absolute Error"
set title "Error Decay Curves for O(h^2), O(h^4), Richardson"

# Grid
set grid

# Plot the three curves

plot "error_data.txt" using 1:2 with linespoints lw 2 pt 7 lc rgb "blue" title "O(h^2)", \
     "error_data.txt" using 1:3 with linespoints lw 2 pt 5 lc rgb "green" title "O(h^4)", \
     "error_data.txt" using 1:4 with linespoints lw 2 pt 9 lc rgb "red" title "Richardson"
