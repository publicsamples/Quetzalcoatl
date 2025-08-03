			
// Multichannel menus
const var MultiChannelTest = Synth.getChildSynth("Quetzalcoatl");


var matrix = MultiChannelTest.getRoutingMatrix();


inline function onOut1Control(component, value)
{
	
	local success = true;
	
	switch(value)
    {
        case 1: 
            matrix.addConnection(0, 0);
            matrix.addConnection(1, 1);
            break;
        case 2: 
            matrix.addConnection(0, 2);
            
          
            success = matrix.addConnection(1, 3);
            break;
        case 3:
            matrix.addConnection(0, 4);
            success = matrix.addConnection(1, 5);
            break;
        case 4:
            matrix.addConnection(0, 6);
            success = matrix.addConnection(1, 7);
            break;
         case 5:
              matrix.addConnection(0, 8);
              success = matrix.addConnection(1, 9);
              break;   
        case 6:
              matrix.addConnection(0, 10);
              success = matrix.addConnection(1, 11);
              break;  
        case 7:
              matrix.addConnection(0, 12);
              success = matrix.addConnection(1, 13);
              break;  
       case 8:
              matrix.addConnection(0, 14);
               success = matrix.addConnection(1, 15);
               break;          
    }
    
    if(!success)
    {
        matrix.addConnection(0, 0);
        matrix.addConnection(1, 1);
    }
    

};

Content.getComponent("Out1").setControlCallback(onOut1Control);


inline function onOut2Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(2, 0);
            matrix.addConnection(3, 1);
            break;
        case 2:
            matrix.addConnection(2, 2);
            success = matrix.addConnection(3, 3);
            break;
        case 3:
            matrix.addConnection(2, 4);
            success = matrix.addConnection(3, 5);
            break;
        case 4:
            matrix.addConnection(2, 6);
            success = matrix.addConnection(3, 7);
            break;
      case 5:
                   matrix.addConnection(2, 8);
                   success = matrix.addConnection(3, 9);
                   break;   
             case 6:
                   matrix.addConnection(2, 10);
                   success = matrix.addConnection(3, 11);
                   break;  
             case 7:
                   matrix.addConnection(2, 12);
                   success = matrix.addConnection(3, 13);
                   break;  
            case 8:
                    matrix.addConnection(2, 14);
                     success = matrix.addConnection(3, 15);
                    break;       
    }
    
    if(!success)
    {
        matrix.addConnection(2, 0);
        matrix.addConnection(3, 1);
    }
    

};

Content.getComponent("Out2").setControlCallback(onOut2Control);



inline function onOut3Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(4, 0);
            matrix.addConnection(5, 1);
            break;
        case 2:
            matrix.addConnection(4, 2);
            success = matrix.addConnection(5, 3);
            break;
        case 3:
            matrix.addConnection(4, 4);
            success = matrix.addConnection(5, 5);
            break;
        case 4:
            matrix.addConnection(4, 6);
            success = matrix.addConnection(5, 7);
            break;
		case 5:
                   matrix.addConnection(4, 8);
                   success = matrix.addConnection(5, 9);
                   break;   
             case 6:
                   matrix.addConnection(4, 10);
                   success = matrix.addConnection(5, 11);
                   break;  
             case 7:
                   matrix.addConnection(4, 12);
                   success = matrix.addConnection(5, 13);
                   break;  
            case 8:
                    matrix.addConnection(4, 14);
                     success = matrix.addConnection(5, 15);
                    break;                
    }
    
    if(!success)
    {
        matrix.addConnection(4, 0);
        matrix.addConnection(5, 1);
    }
    

};

Content.getComponent("Out3").setControlCallback(onOut3Control);



inline function onOut4Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(6, 0);
            matrix.addConnection(7, 1);
            break;
        case 2:
            matrix.addConnection(6, 2);
            success = matrix.addConnection(7, 3);
            break;
        case 3:
            matrix.addConnection(6, 4);
            success = matrix.addConnection(7, 5);
            break;
        case 4:
            matrix.addConnection(6, 6);
            success = matrix.addConnection(7, 7);
            break;
      case 5:
                         matrix.addConnection(6, 8);
                         success = matrix.addConnection(7, 9);
                         break;   
                   case 6:
                         matrix.addConnection(6, 10);
                         success = matrix.addConnection(7, 11);
                         break;  
                   case 7:
                         matrix.addConnection(6, 12);
                         success = matrix.addConnection(7, 13);
                         break;  
                  case 8:
                          matrix.addConnection(6, 14);
                           success = matrix.addConnection(7, 15);
                          break;          
    }
    
    if(!success)
    {
        matrix.addConnection(6, 0);
        matrix.addConnection(7, 1);
    }
    

};

Content.getComponent("Out4").setControlCallback(onOut4Control);

inline function onOut5Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(8, 0);
            matrix.addConnection(9, 1);
            break;
        case 2:
            matrix.addConnection(8, 2);
            success = matrix.addConnection(9, 3);
            break;
        case 3:
            matrix.addConnection(8, 4);
            success = matrix.addConnection(9, 5);
            break;
        case 4:
            matrix.addConnection(8, 6);
            success = matrix.addConnection(9, 7);
            break;
      case 5:
                         matrix.addConnection(8, 8);
                         success = matrix.addConnection(9, 9);
                         break;   
                   case 6:
                         matrix.addConnection(8, 10);
                         success = matrix.addConnection(9, 11);
                         break;  
                   case 7:
                         matrix.addConnection(8, 12);
                         success = matrix.addConnection(9, 13);
                         break;  
                  case 8:
                          matrix.addConnection(8, 14);
                           success = matrix.addConnection(9, 15);
                          break;          
    }
    
    if(!success)
    {
        matrix.addConnection(8, 0);
        matrix.addConnection(9, 1);
    }
    

};

Content.getComponent("Out5").setControlCallback(onOut5Control);


inline function onOut6Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(10, 0);
            matrix.addConnection(11, 1);
            break;
        case 2:
            matrix.addConnection(10, 2);
            success = matrix.addConnection(11, 3);
            break;
        case 3:
            matrix.addConnection(10, 4);
            success = matrix.addConnection(11, 5);
            break;
        case 4:
            matrix.addConnection(10, 6);
            success = matrix.addConnection(11, 7);
            break;
      case 5:
                         matrix.addConnection(10, 8);
                         success = matrix.addConnection(11, 9);
                         break;   
                   case 6:
                         matrix.addConnection(10, 10);
                         success = matrix.addConnection(11, 11);
                         break;  
                   case 7:
                         matrix.addConnection(10, 12);
                         success = matrix.addConnection(11, 13);
                         break;  
                  case 8:
                          matrix.addConnection(10, 14);
                           success = matrix.addConnection(11, 15);
                          break;          
    }
    
    if(!success)
    {
        matrix.addConnection(10, 0);
        matrix.addConnection(11, 1);
    }
    

};

Content.getComponent("Out6").setControlCallback(onOut6Control);


inline function onOut7Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(12, 0);
            matrix.addConnection(13, 1);
            break;
        case 2:
            matrix.addConnection(12, 2);
            success = matrix.addConnection(13, 3);
            break;
        case 3:
            matrix.addConnection(12, 4);
            success = matrix.addConnection(13, 5);
            break;
        case 4:
            matrix.addConnection(12, 6);
            success = matrix.addConnection(13, 7);
            break;
      case 5:
                         matrix.addConnection(12, 8);
                         success = matrix.addConnection(13, 9);
                         break;   
                   case 6:
                         matrix.addConnection(12, 10);
                         success = matrix.addConnection(13, 11);
                         break;  
                   case 7:
                         matrix.addConnection(12, 12);
                         success = matrix.addConnection(13, 13);
                         break;  
                  case 8:
                          matrix.addConnection(12, 14);
                           success = matrix.addConnection(13, 15);
                          break;          
    }
    
    if(!success)
    {
        matrix.addConnection(12, 0);
        matrix.addConnection(13, 1);
    }
    

};

Content.getComponent("Out7").setControlCallback(onOut7Control);


inline function onOut8Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(14, 0);
            matrix.addConnection(15, 1);
            break;
        case 2:
            matrix.addConnection(14, 2);
            success = matrix.addConnection(15, 3);
            break;
        case 3:
            matrix.addConnection(14, 4);
            success = matrix.addConnection(15, 5);
            break;
        case 4:
            matrix.addConnection(14, 6);
            success = matrix.addConnection(15, 7);
            break;
      case 5:
                         matrix.addConnection(14, 8);
                         success = matrix.addConnection(15, 9);
                         break;   
                   case 6:
                         matrix.addConnection(14, 10);
                         success = matrix.addConnection(15, 11);
                         break;  
                   case 7:
                         matrix.addConnection(14, 12);
                         success = matrix.addConnection(15, 13);
                         break;  
                  case 8:
                          matrix.addConnection(14, 14);
                           success = matrix.addConnection(15, 15);
                          break;          
    }
    
    if(!success)
    {
        matrix.addConnection(14, 0);
        matrix.addConnection(15, 1);
    }
    

};

Content.getComponent("Out8").setControlCallback(onOut8Control);
