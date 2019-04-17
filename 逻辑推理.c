#include <stdio.h>
int main()
{
    char i,m,n;
    for (i='X';i<='Z';i++)
    {
    	  for (m='X';m<='Z';m++)
    	  {
    	  	if (i!=m)
    	  	{
    	  		  for (n='X';n<='Z';n++)
    	  		  {
    	  		  	if (n!=m&&n!=i) 
    	  		  	{
    	  		  		if(i!='X'&&n!='X'&&n!='Z')
    	  		  		{
    	  		  		    printf("A与%c PK,B与%c PK,C与%c PK\n",i,m,n);
    	  		  		}
    	  		  	}
    	  		  }
    	  	}
    	  }
    }
    return 0;
}
    		
    