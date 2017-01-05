void delete_record() // ГўГЁГ¤Г Г«ГҐГ­Г­Гї Г§Г ГЇГЁГ±Гі; 
{ 
	watch_file(filename); // ГўГЁГўВіГ¤ ВіГ­ГґГ®Г°Г¬Г Г¶ВіВї; 
	int number; 
	int nume; 
	f=fopen(filename,"r"); // ГўВіГ¤ГЄГ°ГЁГІГІГї; 
	fseek(f,0L,SEEK_END); // ГЇВіГ¤Г°Г ГµГіГ­Г®ГЄ ГЄВіГ«ГјГЄГ®Г±ГІВі Г§Г ГЇГЁГ±ВіГў; 
	fgetpos(f,&ipos); 
	nume=(ipos/sizeof(record)); 
	if (nume==0) printf("File is empty!\n"); else 
	{ 
		do 
		{ 
	printf("\nEnter number of record,which you want to delete: "); // Г­Г®Г¬ГҐГ° ГўГЁГ¤Г Г«ГҐГ­Г­Гї; 
	//cin В» number; 
	//scanf("%d",&number); 
	number=int_checking(number); 
	if (number <=0) printf("Number of record must be bigger than 0"); 
	} while (number<=0); 

	if (number > nume) {printf("Incorrect input. Number of records are less!"); delete_record();} else 
	{ 
	extra=fopen("extra.f","wb"); // Г±ГІГ®ГўГ°ГѕВєГ¬Г® Г¤Г®Г¤Г ГІГЄГ®ГўГЁГ© ГґГ Г©Г«; 
	fseek(f,0L,SEEK_SET); // ГЄГіГ°Г±Г®Г° Гі ГЇГ®Г·Г ГІГ®ГЄ; 
	for (int i = 0; i < nume; i++) 
	{ 
	if (i==(number-1)) // ГґВіГЄГ±ГіГўГ Г­Г­Гї ГўГЁГ¤Г Г«ГҐГ­Г­Гї; 
	{ 
	fseek(f,number*sizeof(record),SEEK_SET); continue; // Г§Г¬ВіГ№ГіВєГ¬Г® ГЄГіГ°Г±Г®Г° Г­Г  Г­Г Г±ГІГіГЇГ­ГЁГ© ГҐГ«ГҐГ¬.; 
	} 
	fread(&region,sizeof(record),1,f); // ГЇГ°Г®Г¤Г®ГўГ¦ГіВєГ¬Г® Г§Г ГЇГЁГ± Гі Г¤Г®Г¤Г ГІГЄГ®ГўГЁГ© ГґГ Г©Г«; 
	fwrite(&region,sizeof(record),1,extra); 
	} 
	fclose(f); 
	fclose(extra); 
	f=fopen(filename,"wb"); // Г§Г Г­Г®ГўГ® ГўВіГ¤ГЄГ°ГЁГўГ ВєГ¬Г® ГґГ Г©Г«; 
	extra=fopen("extra.f","rb"); 
	fseek(f,0L,SEEK_SET); 
	fseek(extra,0L,SEEK_SET); 
	for (int i=0; i< nume-1;i++) // ГЇГҐГ°ГҐГ§Г ГЇГЁГ±ГіВєГ¬Г® Г§ Г¤Г®Г¤Г ГІГЄГ®ГўГ®ГЈГ® Гў Г®Г±Г­Г®ГўГ­ГЁГ© ГґГ Г©Г«; 
	{ 
		fread(&region,sizeof(record),1,extra); 
		fwrite(&region,sizeof(record),1,f); 
	} 
	fclose(f); 
	fclose(extra); 
	remove("extra.f"); 
	system("cls"); 
	watch_file(filename); // ГЇГҐГ°ГҐГЈГ«ГїГ¤ Г§Г ГЇГЁГ±ВіГў; 
	} 
	} 
}