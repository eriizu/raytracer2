/*
** raytracer_messages.h for raytracer1 in /home/elise/delivery/raytracer1/include/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Thu Feb 16 16:35:31 2017 Élise Philippe
** Last update Fri May 26 13:47:56 2017 mael drapier
*/

#ifndef RAYTRACER_MESSAGES_H_
# define RAYTRACER_MESSAGES_H_

# define MSG_FD_ERROR		"\nfile related error: "
# define MSG_FC_ERROR		"\nfile content error: "
# define MSG_MISSING_FILE	"No such file or directory\n"
# define MSG_PERMISSION		"Permission denied\n"
# define MSG_IS_DIR		"Is a directory\n"
# define MSG_UNKNOWN		"Unexpected error\n"
# define MSG_TOO_FEW_ARG	"raytracer: too few arguments\n"
# define MSG_INTERUPTED		"%sraytracer: %serror:%s was not able to\
 continue\nrun terminated.\n"
# define MSG_PLAUSIBLE_WARNING	"%s%s: %swarning:%s configuration file\
 contains an inconsistency.\n"
# define MSG_QUIT		"raytracer: user exited. (ESC)\
\nrun terminated.\n"
# define MSG_RELOAD		"----------------\n\nReloading\n"
# define MSG_RENDER		"\n[\t   ] Rendering with up to 4 threads\r"
# define MSG_RENDER_DONE	"-\x1b[32mCOMPLETE\x1b[0m-\n"
# define LOAD_CHAR		'#'
# define MSG_WIN_OPEN		"\nOpenning window"
# define MSG_SUCCES		" [SUCCESS]\n"
# define HINT_LOAD		"Loading objects from: \'%s\'"
# define HINT_SUMMARY		"Object summary:\n"
# define HINT_SINGLE_OBJ_SUM	"#%d is a %s.\n"
# define HINT_LOAD_FB		"Loading framebuffer from \'%s\'\n"
# define HINT_EXPORT		"\nExport to \'%s\'"
# define HINT_TOTAL_LOADED	"\n%sLoaded %d objects total.%s\n\n"

# define HELPER		HELP_1 HELP_2 HELP_3 HELP_4 HELP_5 HELP_6 H_FLAGS
# define HELP_1		"Raytracer project\n\nDescription:\n"
# define HELP_2		"\t3D layout engine featuring multiple objects\n"
# define HELP_3		"\tincluding spheres, planes, cylinders, cones.\n\n"
# define HELP_4		"Usage:\n"
# define HELP_5		"\t./raytracer2 [-rea | -i] [conf_file.rtc |"
# define HELP_6		" export_file.exp]\n"
# define HELP_7		"Flags:\n"
# define HELP_8		"\t-r:\tstandard rendering\n"
# define HELP_9		"\t-a:\trendering with antialiasing\n"
# define HELP_10	"\t-e:\trendering exported to .exp file\n"
# define HELP_11	"\t-i:\trendering from imported .exp file\n"
# define HELP_12	"Note:\n"
# define HELP_13	"\twithout flags, antialiasing is activated.\n"
# define H_FLAGS	HELP_7 HELP_8 HELP_9 HELP_10 HELP_11 HELP_12 HELP_13

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RST			"\x1b[0m"
# define BOLD			"\033[1m"

# define TYPE_SPHERE		"sphere"
# define TYPE_PLANE		"plane"
# define TYPE_CYLINDER		"cylinder"
# define TYPE_CONE		"cone"
# define TYPE_LIGHT		"light"
# define TYPE_EYE		"camera"
# define TYPE_UNK		"beautiful princess or a rune of hyrule"
# define TYPE_TORUS		"torus"

int	acp_putstr(int, char *);

#endif /* !RAYTRACER_MESSAGES_H_ */
