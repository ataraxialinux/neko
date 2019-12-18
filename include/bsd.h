#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stddef.h>
#include <stdarg.h>

typedef u_int32_t uint32_t;

#define	__attribute__(x)
#define __dead		__attribute__((__noreturn__))
#define __pure		__attribute__((__const__))
#define	__unused	__attribute__((__unused__))

#ifndef __GLIBC__
#if defined(__cplusplus)
#define	__BEGIN_EXTERN_C	extern "C" {
#define	__END_EXTERN_C		}
#else
#define	__BEGIN_EXTERN_C
#define	__END_EXTERN_C
#endif

#define	__BEGIN_DECLS	__BEGIN_EXTERN_C
#define	__END_DECLS	__END_EXTERN_C
#endif

#if !defined(DEF_WEAK)
#define DEF_WEAK(x)
#endif

#define timespeccmp(tsp, usp, cmp)					\
        (((tsp)->tv_sec == (usp)->tv_sec) ?			\
        ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
        ((tsp)->tv_sec cmp (usp)->tv_sec))

uint32_t arc4random(void);
uint32_t arc4random_uniform(uint32_t);

void arc4random_buf(void *, size_t)
	__attribute__((__bounded__ (__buffer__,1,2)));
size_t	 strlcat(char *, const char *, size_t)
		__attribute__ ((__bounded__(__string__,1,3)));
size_t	 strlcpy(char *, const char *, size_t)
		__attribute__ ((__bounded__(__string__,1,3)));
void	 strmode(int, char *);
int	gid_from_group(const char *, gid_t *);
const char	*group_from_gid(gid_t, int);
int	uid_from_user(const char *, uid_t *);
const char	*user_from_uid(uid_t, int);
long long
	strtonum(const char *, long long, long long, const char **);
int		 setpassent(int);
int		 setgroupent(int);
void	*reallocarray(void *, size_t, size_t);
void	*recallocarray(void *, size_t, size_t, size_t);
