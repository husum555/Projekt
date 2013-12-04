Projekt
=======
void psoc_spi_write(int komNr, int brugerNr, char* pref)
{
  //Laver en besked buffer
  int i;
  struct spi_transfer t[1];
  struct spi_message m;

 printk(KERN_ALERT "Modtog komNr: %d - brugerNr: %d og pref\n",komNr, brugerNr);
 
 for(i=0;i<6;i++)
   printk(KERN_ALERT "præference %c fra plads %d", pref[i], i);

 printk(KERN_ALERT "Done printing recieved stuff");


 //Definerer den besked der skal sendes
 char sendByte[13];

 for(i=0;i<12;i++)
   sendByte[i] = '0';
 
 /*Tjekker om vi er tilsluttet en slave*/
 if (!psoc_spi_device)
   printk(KERN_ALERT "Der er ikke tilsluttet en slave");

 //Lav den besked der skal sendes

 sendByte[0] = '1';
 //Kommando-bit
 if(komNr == 0) //Hvis sortering skal startes
   {
     printk(KERN_ALERT "Modtog komNr 0\n");
     sendByte[1] = '0';
     sendByte[2] = '0';
   }
 if(komNr == 1)//Hvis der skal sendes en bruger
   {
     printk(KERN_ALERT "Modtog komNr 1\n");
     sendByte[1] = '1';
     sendByte[2] = '1';
   }
 else if(komNr == 2)//Hvis bruger skal slettes
   {
     printk(KERN_ALERT "Modtog komNr 2\n");
     sendByte[1] = '1';
     sendByte[2] = '0';
   }

//Herefter Brugernummer
switch(brugerNr)
  {
 case 1:
   {
   printk(KERN_ALERT "Modtog brugerNr 1");
   sendByte[3] = '0'; 
   sendByte[4] = '0';
   break;
   }
 case 2:
   {
   printk(KERN_ALERT "Modtog brugerNr 2");
   sendByte[3] = '0'; 
   sendByte[4] = '1';
   break;
   }
 case 3:
   {
   printk(KERN_ALERT "Modtog brugerNr 3");
   sendByte[3] = '1'; 
   sendByte[4] = '0';
   break;
   }
 case 4:
   {
   printk(KERN_ALERT "Modtog brugerNr 4");
   sendByte[3] = '1'; 
   sendByte[4] = '1';
   break;
   }
 default:
   {
   printk(KERN_ALERT "Modtog brugerNr ukendt");
   sendByte[3] = 'x'; 
   sendByte[4] = 'x';
   break;
   }
  }
  
  /* MORE STUFF BELOW */
