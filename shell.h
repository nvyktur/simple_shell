#include "shell.h"

/**
* buff_input - chained commands
* @data: parameter struct
* @buff: address of buffer
* @l: length var
* @Deborah @Victor
* Return: bytes read
*/
ssize_t buff_input(data_t *data, char **buff, size_t *l)
{
ssize_t m = 0;
size_t len = 0;

if (!*l)
{
if (*buff != NULL)
{
free(*buff);
*buff = NULL;
}
signal(SIGINT, handle_sig);
#if USE_GETLINE
m = getline(buff, &len, stdin);
#else
m = next_line(data, buf, &len_p);
#endif
if (m > 0)
{
if ((*buff)[m - 1] == '\n')
{
(*buff)[m - 1] = '\0';
m--;
}
data->linecount_flag = 1;
remove_comments(*buff);
building_list(data, *buff, data->histcount++);
/* if (_strchr(*buff, ';')) is this a chain? */
{
*l = r;
data->command_buff = buff;
}
}
}
return (m);
}

/**
* buff_read - buffer reader
* @data: parameter struct
* @buff: buffer
* @j: size
*
* Return: m
*/
ssize_t buff_read(data_t *data, char *buff, size_t *j)
{
ssize_t m = 0;

if (*j)
return (0);
m = read(data->read_fd, buff, BUFF_READ_SIZE);
if (m >= 0)
*j = m;
return (m);
}

/**
* next_line - gets the next line
* @data: parameter struct
* @pntr: address of pointer to buffer.
* @l: length
* Return: t
*/
int next_line(data_t *data, char **pntr, size_t *l)
{
static char buff[BUFF_READ_SIZE];
static size_t j, len;
size_t b;
ssize_t m = 0, t = 0;
char *h = NULL, *new_h = NULL, *c;

h = *pntr;
if (h && l)
t = *l;
if (j == len)
j = len = 0;

m = buff_read(data, buff, &len);
if (m == -1 || (m == 0 && len == 0))
return (-1);

character = string_char(buff + j, '\n');
b = character ? 1 + (unsigned int)(character - buf) : len;
new_h = _realloc(h, t, t ? t + b : b + 1);
if (!new_h)
return (h ? free(h), -1 : -1);

if (t)
string_n_cat(new_h, buff + j, b - j);
else
string_n_cpy(new_h, buff + j, b - j + 1);

t += b - j;
j = b;
h = new_h;

if (l)
*l = t;
*pntr = p;
return (t);
}

/**
* handles_sig - blocks control-C
* @sig_num: the signal number
* Return: nothing
*/
void handles_sig(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUFF_FLUSH);
}

/**
* input_get - line minus the newline
* @data: parameter struct
* Return: bytes read
*/
ssize_t input_get(data_t *data)
{
static char *buff;
static size_t i, j, l;
ssize_t m = 0;
char **buf = &(data->arg), *h;

_putchar(BUFF_FLUSH);
m = input_buff(data, &buff, &l);
if (m == -1)
return (-1);
if (l)
{
j = t;
h = buff + t;

check_chain(data, buff, &j, t, l);
while (j < l)
{
if (is_chain(data, buff, &j))
break;
j++;
}

t = j + 1;
if (t >= l)
{
t = l = 0;
data->command_buff_type = COMMAND_NORM;
}
*buf = h;
return (_strlen(h));
}

*buf = buff;
return (m);
}
