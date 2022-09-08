#include <cstdio>

// OpenCL includes
#include <CL/cl.h>
#include <CL/cl_platform.h>

int main(int argc, char** argv)
{
    cl_int CL_err = CL_SUCCESS;
    cl_uint numPlatforms = 0;

    CL_err = clGetPlatformIDs( 0, NULL, &numPlatforms );

    cl_platform_id * platforms = new cl_platform_id[ numPlatforms ];
    clGetPlatformIDs( numPlatforms, platforms, 0 );

    if ( CL_err == CL_SUCCESS )
    {
        std::printf( "%u platform(s) found\n", numPlatforms );
        for ( cl_uint i = 0; i < numPlatforms; ++ i )
        {
            std::size_t platform_name_length = 0;
            clGetPlatformInfo( platforms[ i ], CL_PLATFORM_NAME, 0, 0, &platform_name_length );
            char * platform_name = new char[ platform_name_length ];
            clGetPlatformInfo( platforms[ i ], CL_PLATFORM_NAME, platform_name_length, platform_name, 0 );
            std::printf(" [ %d ] %s\n", i, platform_name );

        }
    }
    else
    {
        std::printf( "clGetPlatformIDs(%i)\n", CL_err );
    }

    return 0;
}
