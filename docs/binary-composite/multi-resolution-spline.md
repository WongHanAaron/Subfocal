# Multi-Resolution Spline

The multi-resolution spline is an algorithm that takes two images and blends both images by performing cross-fade blends at multiple levels of the Laplacian pyramid. By blending the images at multiple levels of the Laplacian pyramid, this blending algorithm essentially performs a cross fade between the two images at a different rate for each frequency band of image features in the Fourier domain. 

The regions to be kept from either image is selected through a binary image mask. 



## References
<a id="1">[[1]](https://ai.stanford.edu/~kosecka/burt-adelson-spline83.pdf)</a> 
Peter J. Burt and Edward H. Adelson (1983). <i>A Multi-resolution Spline With Application to Image Mosaics</i> 
ACM Transactions on Graphics, 11(3), 217-236.