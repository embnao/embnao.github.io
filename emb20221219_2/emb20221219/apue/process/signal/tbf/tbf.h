#ifndef __IF_H__
#define __IF_H__

#define TBFNR	1024

// 声明接口
/******************
 *cps:速率
 *burst:上限
 *返回值:桶描述符,令牌桶库的下标值
 *********************/
extern int tbf_init(int cps, int burst);

/********************
 *td:桶描述符
 *ntokens:取的token个数
 *返回值:取到的token个数
 ********************/
extern int tbf_fetch_token(int td, int ntokens);

extern void tbf_destroy(int td);

extern void tbf_destroy_all(void);

#endif

