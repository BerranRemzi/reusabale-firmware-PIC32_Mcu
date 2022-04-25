#ifndef _REFCLK_H    /* Guard against multiple inclusion */
#define _REFCLK_H

#include "typedef_global.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

    bool mod_refclk_conf(const char *ptext);
    bool mod_refclk_enable(bool enable);
    

/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */
