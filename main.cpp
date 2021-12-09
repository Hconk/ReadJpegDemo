#include <itkJPEGImageIO.h>
#include <itkImageFileReader.h>

int main(int, char**) {
    constexpr unsigned int Dimension = 2;
    using PixelType = unsigned char;
    using ImageType = itk::Image<PixelType, Dimension>;
    itk::JPEGImageIO::Pointer io;
    io = itk::JPEGImageIO::New();
    itk::ImageFileReader<ImageType>::Pointer JPEGReader;
    JPEGReader = itk::ImageFileReader<ImageType>::New();
    JPEGReader->SetFileName( "D:/a/ReadJpegDemo/ReadJpegDemo/211869_09365_55_55_old.jpg" );
    JPEGReader->SetImageIO(io);
    try
    {
        JPEGReader->Update();
        std::cout << *JPEGReader->GetOutput();
    }
    catch (itk::ExceptionObject & err)
    {
        std::cerr << "ExceptionObject caught !" << std::endl;
        std::cerr << err << std::endl;
    }
    
    std::cout << "ITK Read Jpeg Demo.\n";
    return 0;
}