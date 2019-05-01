#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void main()
{
	int hh, mm, ss,f,vt,th;
	char h[3], m[3], s[3],tmp[3];
	FILE*ft;
	
	s[2]=m[2]=h[2] = '\0';
	ft = fopen("1.txt", "r");
	int i = 0,k=0;
	char time[10] = {'\0'};
	fgets(time, 9, ft);
	do {
		h[k] = time[i];
		k++;
		i++;
	} while (k!=2);
	i++;
	k = 0;
	do {
		m[k] = time[i];
		k++;
		i++;
	} while (k!=2);
	i++;
	k=0;
	do {
		s[k] = time[i];
		k++;
		i++;
	} while (k!=2);
	hh = atoi(h);
	mm = atoi(m);
	ss = atoi(s);
	printf("%d:%d:%d\n", hh, mm, ss);

	if (hh >= mm && hh >= ss)
	{
		f = hh;
		if (mm >= ss)
		{
			vt = mm;
			th = ss;
		}
		else {
			vt = ss;
			th = mm;
		}
	}
	else if (mm >= ss && mm >= ss)
	{
		f = mm;
		if (hh >= ss)
		{
			vt = hh;
			th = ss;
		}
		else {
			vt = ss;
			th = hh;
		}
	}
	else if (mm >= hh)
	{
		f = ss;
		vt = mm;
		th = hh;
	}
	else {
		f = ss;
		vt = hh;
		th = mm;
	}

	printf("%d:%d:%d\n", f, vt, th);
	fprintf(ft, "\n%d:%d:%d", f, vt, th);


		system("pause");
}