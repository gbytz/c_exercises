int are_equal(const char s[], const char t[])
{
    int i;
    for(i = 0; s[i] != '\0' && t[i] != '\0' && s[i] == t[i]; ++i)
        ;
    return s[i] == t[i];
}
