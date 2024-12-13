#include<stdio.h>
#define max 25
void main()
{
	int frag[max],block_size[max],file_size[max],i,j,no_blocks,no_files,diff,highest=0;
	static int bf[max],block_no[max];
	printf("\n\t Memory Management Scheme - Worst Fit");
	printf("\n Enter the number of blocks:");
	scanf("%d",&no_blocks);
	printf("\n Enter number of files:");
	scanf("%d",&no_files);
	printf("\n Enter the size of the blocks:\n");
	for(i=1;i<=no_blocks;i++)
	{
		printf("Block %d:",i);
		scanf("%d",&block_size[i]);
	}
	printf("Enter the size of the files:\n");
	for(i=1;i<=no_files;i++)
	{
		printf("File %d:",i);
		scanf("%d",&file_size[i]);
	}
	for(i=1;i<=no_files;i++)
	{
		for(j=1;j<=no_blocks;j++)
		{
			if(bf[j]!=1)
			{
				diff=block_size[j]-file_size[i];
				if(highest < diff && diff>=0)
				{
					block_no[i]=j;
					highest=diff;
				}
			}
		}
		frag[i]=highest;
		bf[block_no[i]]=1;
		highest=0;
	}
	printf("\n File_no:\t File_size:\t Block_no:\tBlock_size:\t Fragment");
	for(i=1;i<=no_files;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,file_size[i],block_no[i],block_size[block_no[i]],frag[i]);
}
 
 