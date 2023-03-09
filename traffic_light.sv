module traffic_light (
    input  logic clk_i,     // system clock
    input  logic pedestrian_button_i,   // input for pedestrian button
    output logic red_o, amber_o, green_o  // outputs for each color
);

logic [2:0] Count_GREEN, Count_AMBER, Count_RED, Count_RED_AMBER ;

typedef  enum  logic  [1:0]  {
  GREEN,
  AMBER,
  RED,
  RED_AMBER
}  state;

state current_state, next_state;

always_ff @(posedge clk_i) begin
  current_state <= next_state;
end

always_comb  begin 
  Count_GREEN = 0;
  Count_AMBER = 0;
  Count_RED = 0;
  Count_RED_AMBER = 0;
  case  (current_state)
    GREEN: if (pedestrian_button_i) begin
                   next_state = RED;
                   Count_RED = 3'd0;
           end
		   else begin 
        	    if(Count_GREEN < 5) begin       
        			next_state = GREEN;
        			Count_GREEN = Count_GREEN + 1;
        		end
        		else begin
					next_state       = AMBER;
					Count_GREEN = 3'd0;
        		end
        	end
        		
        AMBER: if (pedestrian_button_i) begin
                      next_state = RED;
                      Count_RED = 3'd0;
               end
			   else begin	
        	   if(Count_AMBER < 1) begin
        	   	 next_state   = AMBER;
        	   	 Count_AMBER = Count_AMBER + 1;
        	   end
        	   else begin
			   	 next_state       = RED;	
        	     Count_AMBER = 3'd0;
        	   end
        	   end
        
        RED:  if (pedestrian_button_i) begin
                 Count_RED = 3'd0;
              end
              else begin
              if (Count_RED < 6) begin
        		  next_state = RED;
        		  Count_RED = Count_RED + 1;
        	  end
              else begin
				next_state	 = RED_AMBER;
				Count_RED_AMBER = 3'd0;
        	  end
        	  end
 	
             	
        RED_AMBER: if (pedestrian_button_i) begin
                        next_state = RED;
                        Count_RED = 3'd0;
                   end
        		   else begin
        			if(Count_RED_AMBER < 1) begin
        	    		next_state	= RED_AMBER;
        	    		Count_RED_AMBER = Count_RED_AMBER + 1;
        	    	end
        	    	else begin	
        	    		next_state   	= GREEN;
        	    		Count_RED_AMBER = 3'd0;					
        	    	end
        	    	end
       default: ;
    endcase
end


assign red_o = (current_state == (RED | RED_AMBER))  ?  1'b1  :  1'b0;
assign green_o = (current_state == GREEN) ? 1'b1 : 1'b0;
assign amber_o = (current_state == AMBER) ? 1'b1 : 1'b0;
endmodule 
