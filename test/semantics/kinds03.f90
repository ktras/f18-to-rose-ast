! Copyright (c) 2019, NVIDIA CORPORATION.  All rights reserved.
!
! Licensed under the Apache License, Version 2.0 (the "License");
! you may not use this file except in compliance with the License.
! You may obtain a copy of the License at
!
!     http://www.apache.org/licenses/LICENSE-2.0
!
! Unless required by applicable law or agreed to in writing, software
! distributed under the License is distributed on an "AS IS" BASIS,
! WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
! See the License for the specific language governing permissions and
! limitations under the License.

 !DEF: /MainProgram1/ipdt DerivedType
 !DEF: /MainProgram1/ipdt/k TypeParam INTEGER(4)
 type :: ipdt(k)
  !REF: /MainProgram1/ipdt/k
  integer, kind :: k
  !REF: /MainProgram1/ipdt/k
  !DEF: /MainProgram1/ipdt/x ObjectEntity INTEGER(int(k,kind=8))
  integer(kind=k) :: x
 end type ipdt
 !DEF: /MainProgram1/rpdt DerivedType
 !DEF: /MainProgram1/rpdt/k TypeParam INTEGER(4)
 type :: rpdt(k)
  !REF: /MainProgram1/rpdt/k
  integer, kind :: k
  !REF: /MainProgram1/rpdt/k
  !DEF: /MainProgram1/rpdt/x ObjectEntity REAL(int(k,kind=8))
  real(kind=k) :: x
 end type rpdt
 !DEF: /MainProgram1/zpdt DerivedType
 !DEF: /MainProgram1/zpdt/k TypeParam INTEGER(4)
 type :: zpdt(k)
  !REF: /MainProgram1/zpdt/k
  integer, kind :: k
  !REF: /MainProgram1/zpdt/k
  !DEF: /MainProgram1/zpdt/x ObjectEntity COMPLEX(int(k,kind=8))
  complex(kind=k) :: x
 end type zpdt
 !DEF: /MainProgram1/lpdt DerivedType
 !DEF: /MainProgram1/lpdt/k TypeParam INTEGER(4)
 type :: lpdt(k)
  !REF: /MainProgram1/lpdt/k
  integer, kind :: k
  !REF: /MainProgram1/lpdt/k
  !DEF: /MainProgram1/lpdt/x ObjectEntity LOGICAL(int(k,kind=8))
  logical(kind=k) :: x
 end type lpdt
 !REF: /MainProgram1/ipdt
 !DEF: /MainProgram1/i1 ObjectEntity TYPE(ipdt(k=1_4))
 type(ipdt(1)) :: i1
 !REF: /MainProgram1/ipdt
 !DEF: /MainProgram1/i2 ObjectEntity TYPE(ipdt(k=2_4))
 type(ipdt(2)) :: i2
 !REF: /MainProgram1/ipdt
 !DEF: /MainProgram1/i4 ObjectEntity TYPE(ipdt(k=4_4))
 type(ipdt(4)) :: i4
 !REF: /MainProgram1/ipdt
 !DEF: /MainProgram1/i8 ObjectEntity TYPE(ipdt(k=8_4))
 type(ipdt(8)) :: i8
 !REF: /MainProgram1/ipdt
 !DEF: /MainProgram1/i16 ObjectEntity TYPE(ipdt(k=16_4))
 type(ipdt(16)) :: i16
 !REF: /MainProgram1/rpdt
 !DEF: /MainProgram1/a2 ObjectEntity TYPE(rpdt(k=2_4))
 type(rpdt(2)) :: a2
 !REF: /MainProgram1/rpdt
 !DEF: /MainProgram1/a4 ObjectEntity TYPE(rpdt(k=4_4))
 type(rpdt(4)) :: a4
 !REF: /MainProgram1/rpdt
 !DEF: /MainProgram1/a8 ObjectEntity TYPE(rpdt(k=8_4))
 type(rpdt(8)) :: a8
 !REF: /MainProgram1/rpdt
 !DEF: /MainProgram1/a10 ObjectEntity TYPE(rpdt(k=10_4))
 type(rpdt(10)) :: a10
 !REF: /MainProgram1/rpdt
 !DEF: /MainProgram1/a16 ObjectEntity TYPE(rpdt(k=16_4))
 type(rpdt(16)) :: a16
 !REF: /MainProgram1/zpdt
 !DEF: /MainProgram1/z2 ObjectEntity TYPE(zpdt(k=2_4))
 type(zpdt(2)) :: z2
 !REF: /MainProgram1/zpdt
 !DEF: /MainProgram1/z4 ObjectEntity TYPE(zpdt(k=4_4))
 type(zpdt(4)) :: z4
 !REF: /MainProgram1/zpdt
 !DEF: /MainProgram1/z8 ObjectEntity TYPE(zpdt(k=8_4))
 type(zpdt(8)) :: z8
 !REF: /MainProgram1/zpdt
 !DEF: /MainProgram1/z10 ObjectEntity TYPE(zpdt(k=10_4))
 type(zpdt(10)) :: z10
 !REF: /MainProgram1/zpdt
 !DEF: /MainProgram1/z16 ObjectEntity TYPE(zpdt(k=16_4))
 type(zpdt(16)) :: z16
 !REF: /MainProgram1/lpdt
 !DEF: /MainProgram1/l1 ObjectEntity TYPE(lpdt(k=1_4))
 type(lpdt(1)) :: l1
 !REF: /MainProgram1/lpdt
 !DEF: /MainProgram1/l2 ObjectEntity TYPE(lpdt(k=2_4))
 type(lpdt(2)) :: l2
 !REF: /MainProgram1/lpdt
 !DEF: /MainProgram1/l4 ObjectEntity TYPE(lpdt(k=4_4))
 type(lpdt(4)) :: l4
 !REF: /MainProgram1/lpdt
 !DEF: /MainProgram1/l8 ObjectEntity TYPE(lpdt(k=8_4))
 type(lpdt(8)) :: l8
end program
