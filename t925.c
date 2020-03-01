//925. 长按键入
//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，
//按键可能会被长按，而字符可能被输入 1 次或多次。
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友
//的名字（其中一些字符可能被长按），那么就返回 True。


bool isLongPressedName(char * name, char * typed)
{
	int i = 0, j = 0;
	while (name[i] != '\0' && typed[j] != '\0')
	{
		if (name[i] == typed[j])
		{
			++i;
			++j;
		}
		else
			++j;
	}
	if (name[i] == '\0')
		return true;
	else
		return false;
}