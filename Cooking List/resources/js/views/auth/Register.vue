<template>
    <div>
        <Header siteName="Register"></Header>
        <Register></Register>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../../components/header/HeaderGlobal';
import Register from '../../components/content/auth/Register';
import Footer from '../../components/footer/Footer';
export default {

  components: {
    Header,
    Register,
    Footer
  }
}
</script>
