
#ifndef ITKWatersheds_EXPORT_H
#define ITKWatersheds_EXPORT_H

#ifdef ITK_STATIC
#  define ITKWatersheds_EXPORT
#  define ITKWatersheds_HIDDEN
#else
#  ifndef ITKWatersheds_EXPORT
#    ifdef ITKWatersheds_EXPORTS
        /* We are building this library */
#      define ITKWatersheds_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ITKWatersheds_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ITKWatersheds_HIDDEN
#    define ITKWatersheds_HIDDEN __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ITKWATERSHEDS_DEPRECATED
#  define ITKWATERSHEDS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ITKWATERSHEDS_DEPRECATED_EXPORT
#  define ITKWATERSHEDS_DEPRECATED_EXPORT ITKWatersheds_EXPORT ITKWATERSHEDS_DEPRECATED
#endif

#ifndef ITKWATERSHEDS_DEPRECATED_NO_EXPORT
#  define ITKWATERSHEDS_DEPRECATED_NO_EXPORT ITKWatersheds_HIDDEN ITKWATERSHEDS_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define ITKWATERSHEDS_NO_DEPRECATED
#endif

#endif
