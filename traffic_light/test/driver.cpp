#define MAX_SIM 20

void set_random(Vtop *dut, vluint64_t sim_unit) {
	dut -> pedestrian_button_i = (rand ()%2 >= 1);  
}
