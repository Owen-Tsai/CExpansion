/*
 * File Reader source
 * This file contains file reading functions
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */


#include <string.h>
#include <stdarg.h>
#include <ctype.h>

int ReadFile(FILE *fp, char *format, ...) {
    va_list args;
    int tmp;
    char *ch, *s;
    int *i;
    float *f;
    int count, k;

    int len = strlen(format);

    va_start(args, format);

    for(count = 0, k = 2; k < len; k ++) {
        while((tmp = getc(fp)) != EOF) {
            if(tmp >= 0 && tmp <= 127) {
                ungetc(tmp, fp);
                break;
            }
        }

        if(tmp == EOF) {
            break;
        }

        // Read char
        if(format[k - 1] == 'c') {
            ch = va_arg(args, char*);
            count += fscanf(fp, "%c", ch);
        }

        // Read int
        if(format[k - 1] == 'd') {
            i = va_arg(args, int*);
            while((tmp = getc(fp)) != EOF) {
                if((tmp > '0' && tmp < '9') || tmp == '-' || tmp == '+') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            if(tmp != EOF) {
                count += fscanf(fp, "%d", i);
            }
        }

        // Read float
        if(format[k - 1] == 'f') {
            f = va_arg(args, float*);
            while((tmp = getc(fp)) != EOF) {
                if((tmp > '0' && tmp < '9') || tmp == '-' || tmp == '+' || tmp == '.') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            if(tmp != EOF) {
                count += fscanf(fp, "%f", f);
            }
        }

        // Read string
        if(format[k - 1] == 's') {
            s = va_arg(args, char*);
            while((tmp = getc(fp)) != EOF && (!isprint(tmp) || tmp == ' '));

            int n = 0;
            if(!feof(fp)) {
                ungetc(tmp, fp);
                while((tmp = getc(fp)) != EOF) {
                    if(isprint(tmp) && tmp == ' ') {
                        s[n++] = tmp;
                    } else {
                        break;
                    }
                }
                ungetc(tmp, fp);
            }

            s[n] = '\0';
            count ++;
        }
    }

    va_end(args);
    return count;
}
