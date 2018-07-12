char afterWin()
{
	printf("\n*******************************************\n");
	printf("************You've won the game************");
	printf("\n*******************************************\n");

	printf("\nDo you want to continue?\ny/n?\n");
	char des;
	scanf("%c", &des);
	return des;

}