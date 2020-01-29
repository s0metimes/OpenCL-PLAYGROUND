#include<iostream>
#ifdef __APPLE__
	#include<OpenCL/cl.hpp>
#else
	#include<CL/cl.h>
#endif

int main() {
	// get all platforms (drivers), e.g. NVIDIA
	std::vector<cl::Platform> all_platforms;
	cl::Platform::get(&all_platforms);
	
	if(all_platforms.size() == 0) {
		std::cout<<" No platforms found. Check OpenCL installation!\n";
		exit(1);
	}
	cl::Platform default_platform=all_platforms[0];
	std::cout << "Using platform: "<<default_platform.getInfo<CL_PLATFORM_NAME>()<<"\n";
	
	// get default device (CPUs, GPUs) of the default platform
	std::vector<cl::Device> all_devices;
	default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
	if(all_devices.size() == 0) {
		std::cout<<" No devices found. Check OpenCL installation!\n";
		exit(1);
	}

	// use device[1] because that's a GPU; device[0] is the CPU
	cl::Device default_device = all_devices[1];
	std::cout<<"Using device: "<<default_device.getInfo<CL_DEVICE_NAME>()<<"\n";
	
	// a context is like a "runtime line" to the device and platform;
	// i.e. communication is possible
	cl::Context context({default_device});
	
	// create the program that we want to execute on the device
	cl::Program::Sources sources;
	
	//TODO: Currently writing some codes in OpenCL is in process.
	//      Make sure you read the textbook clearly to understand the structure of OpenCL
	//      and try to run code in GPU by OpenCL.
	//      Compare good codes and bad codes to see the difference between them.
	//      2020.01.20 written by s0metimes (Sihwan Oh Marco).
	
	
	int *A = (int*)malloc(sizeof(int) *16384);
	int *B = (int*)malloc(sizeof(int) *16384);
	int *C = (int*)malloc(sizeof(int) *16384);

}


