#include <cstdio>

// OpenCL includes
#include <CL/cl.h>

int main(int argc, char** argv)
{
    cl_int CL_err = CL_SUCCESS;
    cl_uint numPlatforms = 0;

    CL_err = clGetPlatformIDs( 0, NULL, &numPlatforms );

    if (CL_err == CL_SUCCESS)
        std::printf("%u platform(s) found\n", numPlatforms);
    else
        std::printf("clGetPlatformIDs(%i)\n", CL_err);

    return 0;
}
