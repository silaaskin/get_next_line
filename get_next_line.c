/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:24:40 by saskin            #+#    #+#             */
/*   Updated: 2024/12/12 21:20:48 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *str, char *remainder)
{
    int i = 0;
    char *newstr;
    ssize_t bytes_read;
    bytes_read = 1;
if(!remainder)
    remainder = ft_strdup("");
while(bytes_read != 0)
{
 bytes_read = read(fd, str, BUFFER_SIZE);
 if(bytes_read == -1)
{
    free(str);
    return NULL;
}
if(bytes_read == 0)
    break;

newstr = ft_strjoin(remainder, str);

if((ft_strchr(str, '\n')))
{
    remainder = ft_strchr(str, '\n') + 1;
    break;
}
}
return newstr;
}


char *get_next_line(int fd)
{
    char *str;
    static char *remainder;
    char *newstr;
    char *new;
    if(fd <= 0 || BUFFER_SIZE <= 0)
        return NULL;
    str = malloc( BUFFER_SIZE + 1);
    if(!str)
        return NULL;
    newstr =read_line(fd, str, remainder);
    return newstr;
}
int main()
{
    int fd = open("sila.txt",O_RDWR | O_CREAT, 0644);
    write(fd,"sila \n askin \n 42 istanbul", 26);
    get_next_line(fd);
}
// #include "get_next_line.h"

// char *read_line(int fd, char *str, char *remainder)
// {
//     ssize_t bytes_read;
//     char *newstr;

//     // Eğer kalan veri varsa (remainder), onu yeni bir string olarak başlatıyoruz
//     if (remainder)
//     {
//         newstr = ft_strdup(remainder);
//         free(remainder);
//         remainder = NULL; // remainder'ı sıfırlıyoruz
//     }
//     else
//     {
//         newstr = malloc(1); // Başlangıçta boş bir string ayırıyoruz
//         newstr[0] = '\0';
//     }

//     while (1)
//     {
//         bytes_read = read(fd, str, BUFFER_SIZE);
//         if (bytes_read == -1) // Eğer okuma başarısızsa
//         {
//             free(str);
//             free(newstr);
//             return NULL;
//         }

//         if (bytes_read == 0) // Eğer dosyada daha veri kalmadıysa
//             break;

//         str[bytes_read] = '\0'; // Okunan verinin sonuna null terminator ekliyoruz

//         // Okunan veriyi newstr'e ekliyoruz
//         newstr = ft_strjoin(newstr, str);

//         // Eğer '\n' karakteri bulursak, satır tamamlanmış demektir
//         if (ft_strchr(str, '\n'))
//         {
//             remainder = ft_strdup(ft_strchr(str, '\n') + 1); // '\n' sonrası kısmı remainder'a kaydediyoruz
//             break;
//         }
//     }

//     free(str); // str'yi serbest bırakıyoruz
//     return newstr;
// }

// char *get_next_line(int fd)
// {
//     char *str;
//     static char *remainder;
//     char *newstr;

//     if (fd <= 0 || BUFFER_SIZE <= 0) // Dosya geçerli değilse
//         return NULL;

//     str = malloc(BUFFER_SIZE + 1); // Okuma için bir buffer ayırıyoruz
//     if (!str)
//         return NULL;

//     newstr = read_line(fd, str, remainder); // Satırı okuyup döndür
//     return newstr;
// }
