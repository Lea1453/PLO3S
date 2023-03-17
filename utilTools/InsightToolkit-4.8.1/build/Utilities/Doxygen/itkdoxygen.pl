# for vxl files run the vxl_doxy.pl script, and use itkgroup.pl for all other files
if ( $ARGV[0] =~ /(vxl|vcl|vnl)/)
{
    system ("perl /home/jeremy/kit/InsightToolkit-4.8.1/Utilities/Doxygen/vxl_doxy.pl $ARGV[0]");
}
else
{
    system ("perl /home/jeremy/kit/InsightToolkit-4.8.1/Utilities/Doxygen/itkgroup.pl $ARGV[0]");
}
