#ifndef E_MOD_MAIN_H
#define E_MOD_MAIN_H

#include "config.h"
#ifdef HAVE_GETTEXT
# include <libintl.h>
# define D_(string) dgettext(LOCALEDOMAIN, string)
#else
# define bindtextdomain(domain,dir)
# define bind_textdomain_codeset(domain,codeset)
# define D_(string) (string)
#endif
#define N_(string) (string)

#define VALUE_FMT_STR 0
#define VALUE_FMT_NUM 1

typedef struct _Config      Config;
typedef struct _Config_Face Config_Face;
typedef struct _Moon        Moon;
typedef struct _Moon_Face   Moon_Face;

struct _Config
{
   int        show_phase_value;
   int        value_format;
   int        show_border;
   int        show_cloud_anim;
   double     poll_time;
   Eina_List *faces;

   E_Config_Dialog *config_dialog;
   E_Menu          *menu;
};

EAPI extern E_Module_Api e_modapi;

EAPI void *e_modapi_init     (E_Module *m);
EAPI int   e_modapi_shutdown (E_Module *m);
EAPI int   e_modapi_save     (E_Module *m);

void moon_config_init(E_Module *m);
void moon_config_shutdown();
void moon_config_dialog_show(Evas_Object *o);
void moon_reset();

extern Config *moon_config;

#endif

