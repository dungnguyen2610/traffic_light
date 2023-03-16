module traffic_light (
    input  logic clk_i,     // system clock
    input  logic pedestrian_button_i,   // input for pedestrian button
    output logic red_o, amber_o, green_o  // outputs for each color
);

logic [3:0] state;   // state variable to keep track of current state
logic [3:0] Count_GREEN = 0 ;
logic [3:0] Count_AMBER = 0 ;
logic [3:0] Count_RED = 0   ;
logic [3:0] Count_RED_AMBER = 0 ;

parameter IDLE = 4'b0000;
parameter GREEN = 4'b0001;
parameter AMBER = 4'b0010;
parameter RED = 4'b0100;
parameter RED_AMBER = 4'b1000;

// state transition logic
always_ff @(posedge clk_i) begin
    case (state)
        IDLE: if (pedestrian_button_i) begin 
        		  state <= RED;
        	  end	  
              else begin
              	  state <= GREEN;
              end
 
        GREEN: if (pedestrian_button_i) begin
                   state <= RED;
               end
			   else begin
        	    if(Count_GREEN < 5) begin       
        			red_o   <= 1'b0;
            		amber_o <= 1'b0;
                	green_o <= 1'b1;
        			state <= GREEN;
        			Count_GREEN <= Count_GREEN + 1;
        		end
        		else begin
					state       <= AMBER;
					Count_GREEN <= 0;
        		end
        		end
        		
        AMBER: if (pedestrian_button_i) begin
                      state <= RED;
               end
			   else begin	
        	   if(Count_AMBER < 1) begin
        	  	 red_o   <= 1'b0;
               	 amber_o <= 1'b1;
              	 green_o <= 1'b0;
        	   	 state   <= AMBER;
        	   	 Count_AMBER <= Count_AMBER + 1;
        	   end
        	   else begin
			   	 state       <= RED;	
        	     Count_AMBER <= 0;
        	   end
        	   end
        
        RED:   if (Count_RED < 6) begin
        	    red_o   <= 1'b1;
            	amber_o <= 1'b0;
                green_o <= 1'b0; 
        		state <= RED;
        		Count_RED <= Count_RED + 1;
        	  	end
        	  	else begin
				state	 <= RED_AMBER;
				Count_RED_AMBER <= 0;
        	  	end
 	
             	
        RED_AMBER: if (pedestrian_button_i) begin
                        state <= RED;
                   end
        		   else begin
        			if(Count_RED_AMBER < 1) begin
        				red_o   <= 1'b1;
            			amber_o <= 1'b1;
                		green_o <= 1'b0;	
        	    		state	<= RED_AMBER;
        	    		Count_RED_AMBER <= Count_RED_AMBER + 1;
        	    	end
        	    	else begin	
        	    		state   		<= GREEN;
        	    		Count_RED_AMBER <= 0;					
        	    	end
        	    	end
       default: ;
    endcase
end

endmodule

