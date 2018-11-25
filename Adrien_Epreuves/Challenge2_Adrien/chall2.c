// FIC 2019
// CDAISI Adri

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void check();
int lire(char *chaine, int longueur);
int main() {
	
	int i =1;
	char chr;
	int point = 1;
   char input[254];

   char pass[254];
   char passcheck[254]="root";
	
	printf(" C2960 Boot Loader (C2960-HBOOT-M) Version 12.2(25r)FX, RELEASE SOFTWARE (fc4)\n");
	printf(" Cisco WS-C2960-24TT (RC32300) processor (revision C0) with 1K bytes of memory.\n");
	printf(" 2960-24TT starting...\n");
	printf(" Base ethernet MAC Address: 000A.41DD.D9C7\n");
	printf(" Xmodem file system is available.\n");
	printf(" Initializing Flag...\n");
	sleep(i);
	printf(" flag[70 6C 65 61 73 65 20]: 1 files, 0 directories\n");   
	printf(" flag[64 6F 6E 74 20 62 72]: 0 orphaned files, 0 orphaned directories\n");
	printf(" flag[65 61 6B 20 6D 79 20]: Total bytes: 64016384\n");
	printf(" flag[63 6F 64 65]: Bytes used: 4414921\n");
	printf(" flag[.] flag fsck took 1 seconds.\n");
	sleep(i);
	printf("...done Initializing Flag.\n");
	printf("\n");
	printf(" Boot Sector Filesystem (bs:) installed, fsid: 3\n");
	printf(" Parameter Block Filesystem (pb:) installed, fsid: 4\n");
	printf("\n");
	sleep(i);
	printf(" Loading flash:/c2960-lanbase-mz.122-25.FX.bin...\n");
	printf("[OK]\n");
    printf(" Restricted Rights Legend\n");
	printf("\n");
	sleep(i);
	printf(" WS-C2960-24TT (RC32300) processor (revision C0) with 73 68 6F 77 20 76 6C 61 6E 20 62 72 69 65 66K bytes of memory.\n");
	printf("\n");
	printf(" 24 FastEthernet/IEEE 802.3 interface(s)\n");
	printf(" 2 Gigabit Ethernet/IEEE 802.3 interface(s)\n");
	sleep(i);
	printf("\n"); 
	printf(" 1K bytes of flash-simulated non-volatility configuration memory.\n");
	printf(" Base ethernet MAC Address       : 4E 6F 6E 2D 63 6F 6E 73 63 69\n");
	printf(" Motherboard assembly number     : 65 6E 74 69 6F 75 73 20 61 64\n");
	printf(" Power supply part number        : 6D 69 6E 69 73 74 72 61 74 6F \n");
	printf(" Motherboard serial number       : 72\n");
	printf(" Power supply serial number      : DCA102133JA\n");
	printf(" Model revision number           : B0\n");
	printf(" Motherboard revision number     : C0\n");
	printf(" Model number                    : WS-C2960-24TT\n");
	printf(" Information about my password   : 65 61 73 79 20 70 \n");
	printf(" Other Information               : 61 73 73 77 6F 72 64\n");
	printf(" Top Assembly Revision Number    : none\n");
	printf(" Version ID                      : V02\n");
	printf(" CLEI Code Number                : COM3K00BRA\n");
	printf(" Hardware Board Revision Number  : 0x01\n");
	printf("\n");
	sleep(i);
	printf(" Switch   Ports  Model              SW Version              SW Image\n");
	printf(" ------   -----  -----              ----------              ----------\n");
	printf(" *    1   26     WS-C2960-24TT      12.2                    C2960-LANBASE-M\n");
	printf("\n");
	sleep(i);

		while ( point == 1) {

		  	 printf("Switch> "); //enable 

		   	 scanf("%s",input); 

		   	if(strcmp(input,"enable")){
		   	
		   		printf("Unknown command '%s' \n",input);	
		   	}
		   	else{
		   		
		   		printf("Password : ");
		   		scanf("%s",pass);

		   		if(strcmp(pass,passcheck)){
		   		
		   			printf("Wrong Password  \n");	
		   		
		   			}else{
							point=0;
							check();
		   			
		   	 				}
		   	 	}
		   	}


	return 0;
}

void check() {
	int i =1;
  	 int point2=1;
     char input2[254];
     char notflag[254]="46 6C 61 67 20 69 73 20 6E 6F 74 20 68 65 72 65";
   	 while (point2==1){
   	 		
   	 			printf("Switch# "); //here password
   	 			lire(input2, 254);
   	 			if(strcmp(input2,"show vlan brief")==0){ //76 6C 61 6E command
   	 				printf(" VLAN Name                             Status    Ports\n");
   	 				sleep(i);
					printf(" ---- -------------------------------- --------- -------------------------------\n");
					printf(" 1    default                          active   Fa0/1, Fa0/2, Fa0/3, Fa0/4\n");
                    printf(" 							Fa0/5, Fa0/6, Fa0/7, Fa0/8\n");
                    printf(" ----\n");
					printf(" 3    Flag					Fa0/56, Fa0/6C, Fa0/61, Fa0/6E\n");
					printf(" 						Fa0/49, Fa0/73, Fa0/43, Fa0/6F\n");
					printf(" 						Fa0/6F, Fa0/6F, Fa0/6F, Fa0/6C\n");
					printf(" ----\n");
					printf(" 5    Admin					Fa0/21, Fa0/22, Fa0/23, Fa0/24\n");
					printf("						Gig0/1, Gig0/2\n");
					printf(" ----\n");
					sleep(i);
					printf(" 1002 fddi-default                     active\n");
					printf(" 1003 token-ring-default               active\n");
					printf(" 1004 fddinet-default                  active\n");
					printf(" 1005 trnet-default                    active\n");
					
   	 			}
   	 			else if (strcmp(input2,"exit")==0){ //exit command
   	 				
   	 				printf("exit\n");
   	 				printf(notflag); //nice try
   	 				printf("\n");
					point2=0;
   	 			}else{
   	 				printf("Unknown command '%s' \n",input2);
   	 			     }
   }
   
}

int lire(char *chaine, int longueur)

{

    char *positionEntree = NULL;



    if (fgets(chaine, longueur, stdin) != NULL)

    {

        positionEntree = strchr(chaine, '\n');

        if (positionEntree != NULL) 

        {

            *positionEntree = '\0';

        }

        return 1; 

    }

    else

    {

        return 0; 

    }

}






