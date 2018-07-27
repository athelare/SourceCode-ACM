void Build_AC_automation(Node *root)
{
	head=0,tail=0;//队列头、尾指针 
	queue[head++]=root;//先将root入队 
	while(head!=tail)
	{
		Node *p=NULL;
		Node *temp=queue[tail++];//弹出队头结点 
		for(int i=0;i<26;i++)
		{
			if(temp->next[i]!=NULL)//找到实际存在的字符结点 
			{ //temp->next[i] 为该结点，temp为其父结点 
				if(temp==root)//若是第一层中的字符结点，则把该结点的失败指针指向root 
					temp->next[i]->fail=root;
				else
				{
					//依次回溯该节点的父节点的失败指针直到某节点的next[i]与该节点相同，
                	//则把该节点的失败指针指向该next[i]节点； 
                	//若回溯到 root 都没有找到，则该节点的失败指针指向 root
					p=temp->fail;//将该结点的父结点的失败指针给p 
					while(p!=NULL)
					{
						if(p->next[i]!=NULL)
						{
							temp->next[i]->fail=p->next[i];
							break;
						}
						p=p->fail;
					}
					//让该结点的失败指针也指向root 
					if(p==NULL)
						temp->next[i]->fail=root;
				}
				queue[head++]=temp->next[i];//每处理一个结点，都让该结点的所有孩子依次入队 
			}
		}
	}
}
