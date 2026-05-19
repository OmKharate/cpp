void execute()
{
    while(true)
    {
        // Fetch instruction
        for(int i=0;i<4;i++)
            IR[i] = M[IC][i];

        IC++;

        // HALT
        if(IR[0] == 'H')
        {
            cout << "\nProgram Halted";
            break;
        }

        int loc = (IR[2]-'0')*10 + (IR[3]-'0');

        // LR
        if(IR[0]=='L' && IR[1]=='R')
        {
            for(int i=0;i<4;i++)
                R[i] = M[loc][i];
        }

        // SR
        else if(IR[0]=='S' && IR[1]=='R')
        {
            for(int i=0;i<4;i++)
                M[loc][i] = R[i];
        }

        // CR
        else if(IR[0]=='C' && IR[1]=='R')
        {
            C = 1;

            for(int i=0;i<4;i++)
            {
                if(R[i] != M[loc][i])
                {
                    C = 0;
                    break;
                }
            }
        }

        // BT
        else if(IR[0]=='B' && IR[1]=='T')
        {
            if(C == 1)
                IC = loc;
        }
    }
}