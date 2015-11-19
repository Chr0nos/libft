//s1 = chaine
//s2 = pattern

int     ft_match(char *s1, char *s2)
{
    if (!*s1)
    {
        if (*s2 == '*')
            return (ft_match(s1, s2 + 1));
        return ((*s2 == 0 ? 1 : 0));
    }
    else if (*s2 == '*')
    {
        if (s2[1])
        {
            if (!s2[1])
                return (1);
            else if (s2[1] == '*')
                return (ft_match(s1, s2 + 1));
            else if (s2[1] == *s1)
                return (ft_match(s1 + 1, s2 + 2));
            return (ft_match(s1 + 1, s2));
        }
        return (1);
    }
    else if (*s2 == *s1)
        return (ft_match(s1 + 1, s2 + 1));
    return (0);
}
