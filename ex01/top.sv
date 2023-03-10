module top (
// input
input logic clk_i,
input logic pedestrian_button_i,
// output
output logic red_o,amber_o,green_o
);

traffic_light dut (
       .clk_i (clk_i),
       .pedestrian_button_i (pedestrian_button_i),
       .red_o (red_o),
       .amber_o(amber_o),
       .green_o(green_o)
     );
	endmodule : top
