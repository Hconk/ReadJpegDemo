#include <itkJPEGImageIO.h>
#include <itkImageFileReader.h>
#include <itkTIFFImageIO.h>


void jpg_test()
{
    constexpr unsigned int Dimension = 2;
    using PixelType = unsigned char;
    using ImageType = itk::Image<PixelType, Dimension>;
    itk::JPEGImageIO::Pointer io;
    io = itk::JPEGImageIO::New();
    itk::ImageFileReader<ImageType>::Pointer JPEGReader;
    JPEGReader = itk::ImageFileReader<ImageType>::New();
    JPEGReader->SetFileName( "D:/a/ReadJpegDemo/ReadJpegDemo/211869_09365_55_55.jpg" );
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
}

bool tiff_test(const std::string &filename)
{
    
  itk::ImageIOBase::Pointer imageIO = itk::ImageIOFactory::CreateImgeIO(filename.c_str(), itk::ImageIOFactory::ReadMode);
   
  if(imageIO.IsNull) {
    std::cout << "fail create Image io." << std::endl;
    return false;
  }
  

  imageIO-SetFileName(filename);
  imageIO->ReadImageInfomation();
  std::cout << "image pixel type: " << imageIO->GetComponentType() << std::endl;
  std::cout << "image dim: " << imageIO->GetNumberOfDimensions() << std::endl;
  return true;
}

int main(int, char**) {
    jpg_test();
    tiff_test(""D:/a/ReadJpegDemo/ReadJpegDemo/tiff_bug_1.tif"");
    return 0;
}
