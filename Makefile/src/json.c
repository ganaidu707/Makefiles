#include<stdio.h>
#include<json-c/json.h>
#include<string.h>

static char * buffer = 0;

static char* read_data(){
	
	long length;
	FILE * file = fopen ("/home/ganaidu707/Desktop/Makefile/dependencies/document.json", "r");

	if (file)
	{
	  fseek (file, 0, SEEK_END);
	  length = ftell (file);
	  fseek (file, 0, SEEK_SET);
	  buffer = malloc (length);
	  if (buffer)
	  {
		fread (buffer, 1, length, file);
	  }
	  fclose (file);
	}
	
	return buffer;
}

int json_parse_input(json_object *jobj, char* key){
	int result = 0;
	int exists, i, j, k, l, m;
    json_object *mainObj, *NodeObj, *LeafObj, *Leaf_nObj, *tmpmain, *tmpNode, *tmpCtrl, *obj;
    
    int json_obj_type = 0;
    
    exists = json_object_object_get_ex(jobj, "main", &mainObj);
    if (FALSE == exists)
    {
        printf( "\"mainObj\" not found in JSON\n" );
        return 1;
    }
    
    for (i = 0; i < json_object_array_length(mainObj); i++ ){
    	tmpmain = json_object_array_get_idx(mainObj, i);
    	
    	exists = json_object_object_get_ex(tmpmain, "node0", &NodeObj);
        if ( FALSE == exists )
        {
            printf( "\"node0\" not found in JSON\n" );
            return 1;
        }
        for ( j = 0; j < json_object_array_length( NodeObj ); j++ )
        {
            tmpNode = json_object_array_get_idx ( NodeObj, j );

            /* Get values */
            exists = json_object_object_get_ex( tmpNode, "leaf0", &LeafObj );
            if ( FALSE == exists )
            {
                printf( "\"leaf0\" not found in JSON\n" );
                return 1;
            }
            for ( k = 0; k < json_object_array_length( LeafObj ); k++ )
            {
                tmpCtrl = json_object_array_get_idx ( LeafObj, k );
                exists = json_object_object_get_ex( tmpCtrl, "leaf0_1", &Leaf_nObj );
		        if ( FALSE == exists )
		        {
		            printf( "\"leaf0_1\" not found in JSON\n" );
		            return 1;
		        }
		        printf("key = %s\n", key);       		        
		        exists = json_object_object_get_ex( Leaf_nObj, key, &obj );
		        if (exists == TRUE )
		        {
		        	json_obj_type = 1;
		            printf( "key = %s found in Leaf_nObj, json_obj_type = %d\n", key, json_obj_type);
		            	            
		        }
  
		        
		   }
		        
		        switch(json_obj_type){
		        case 1: 
		        	result = json_object_get_int(json_object_object_get(Leaf_nObj, key));
		        break;
		        default:
		        	break;
		        
		        }
		        
		        printf("result = %d\n\n", result);
                
            }
        }
        
        return result;
    
}


	

int json_parse_values(char* key_value){
	int result = 0;
	buffer = read_data();
	json_object *new_obj = json_tokener_parse(buffer);
	
	result = json_parse_input(new_obj, key_value);
	
	json_object_put(new_obj);	
		
	
	return result;
	
}

