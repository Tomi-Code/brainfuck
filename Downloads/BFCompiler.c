static uint8 BFCompiler(void)
{ 
	volatile uint8 program[] = "+++++[>+++++<-]>+.[-]++++++++[>++++++++<-]>++++++++.---.+++++++..+++.";
	volatile uint8 data[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	volatile uint8 out[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	volatile uint8 *p = data;
	volatile uint8 *c = out;
	volatile uint8 *cycleStart = 0;
	volatile uint8 *readPointer = program;
	volatile uint8 symbol = 0;
	
	do
	{
		symbol = *readPointer++;
		switch(symbol)
		{
			case '>':
				p++;
				break;
			case '<':
				p--;
				break;
			case '+':
				p[0]++;
				break;
			case '-':
				p[0]--;
				break;
			case '.':
				*c++ = *p;
				break;
			case ',':
				//*p = getchar();
				break;
			case '[':
				cycleStart = readPointer;
				break;
			case ']':
				if ( cycleStart && *p != 0u )
				{
					readPointer = cycleStart;
				}
				else
				{
					cycleStart = 0;
				}
				break;
		}
		if( p < data || p >= ( data + sizeof(data) ) )
		{
			//error out of memory
		}
	}while(symbol);
	
	while( p > data )
	{
		p--;
	}
	return *p++;
}