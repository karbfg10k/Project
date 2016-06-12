/// Represents a matrix in row-major order
pub type Matrix = Vec<Vec<f32>>;

/// Computes the product of the inputs `mat1` and `mat2`.
pub fn mat_mult(mat1: &Matrix, mat2: &Matrix) -> Matrix {
    assert_eq!(mat1[0].len(), mat2.len());
    
    let mut mat_product = Matrix::new();

    for i in 0..mat1.len() {
        let mut sum: Vec<f32> = vec![0.; mat2[0].len()];
        for j in 0..mat1[0].len() {
            for k in 0..mat2[0].len() {
                sum[k] += mat1[i][j] * mat2[j][k];
            }
        }
        mat_product.push(sum)
    }

    mat_product
}
