main()	
{
	FILE *fo;
	char c, *dest;
	int i;
	char *cp;
	double d;

	dest = "TESTE.TXT";
	if((fo = fopen(dest,"w")) == NULL) {
		printf("Nao Posso ABRIR TESTE.TXT");
		exit();
	}
	c = 'A';
	i = 999;
	cp = "abcdefgh";
	d = 123.456;
	fprintf(fo,"%c %d %s %lf\n", c, i, cp, d);
	fclose(fo);
}

