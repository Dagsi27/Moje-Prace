<template>
    <div>
        <Header siteName="Login"></Header>
        <Login></Login>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../../components/header/HeaderGlobal';
import Login from '../../components/content/auth/Login';
import Footer from '../../components/footer/Footer';
export default {

  components: {
    Header,
    Login,
    Footer
  }
}
</script>
